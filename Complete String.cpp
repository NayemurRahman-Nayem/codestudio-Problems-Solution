struct Node {
	Node * links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}
	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}
	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}
	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};

string completeString(int n, vector<string> &a){

	Trie T ; 
	int len = 0 ; 
	string ans = "-1" ;
	for(int i=0;i<n;i++) T.insert(a[i]) ; 
	for(int i=0;i<n;i++) {
        bool ok = true ; 
        string temp = "" ;  
        for(int j=0;j<a[i].size();j++) {
            temp += a[i][j] ; 
            if(!T.search(temp)) {
                ok = false ; 
                break ; 
            }
        }
        if(ok and a[i].size()>len) {
        	len = a[i].size() ; 
            ans = a[i]  ; 
        }
		else if(ok and a[i].size()==len and a[i]<ans) {
			ans = a[i] ; 
		}
    }
	if(ans=="-1") return "None" ; 
	else return ans ; 
}
