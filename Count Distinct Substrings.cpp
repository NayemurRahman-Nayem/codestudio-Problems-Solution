struct Node {
    Node * links[26] ; 
    bool containkey(char c) {
        return (links[c-'a']!=NULL) ; 
    }
    void put(char c , Node *node) {
        links[c-'a'] = node ; 
    }
    Node * get(char c) {
        return links[c-'a'] ;  
    }
};


int countDistinctSubstrings(string &s)
{
    int cnt = 0 ; 
    int n = s.size() ; 
    Node * root = new Node() ; 
    for(int i=0;i<n;i++) {
        Node * node = root ; 
        for(int j=i;j<n;j++) {
            if(!node->containkey(s[j])) {
                cnt ++ ; 
                node->put(s[j],new Node()) ; 
            }
            node = node->get(s[j]) ;
        } 
    }
    return cnt+1 ; 
}
