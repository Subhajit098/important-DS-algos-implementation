//  DSU by Path Compression
bool findParent(int node,vector<int>& parent){
    if(node==parent[node]){
        return node;
    }

    parent[node]=findParent(parent[node],parent);
}

// DSU by rank
void union_by_rank(int x,int y,vector<int>& parent,vector<int> &rank){
    int x_parent=findParent(x,parent);
    int y_parent=findParent(y,parent);

    if(x_parent==y_parent) return ;

    // if one's rank is more attach the less ranked one to the higher one to reduce the branching effect
    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    } else if(rank[x_parent]<rank[y_parent]){
        parent[x_parent]=y_parent;
    } else {
        parent[x_parent]=y_parent;  // if ranks are same for both make any one of them as parent and increase the parent's rank;
        rank[y_parent]++;
    }

    return ;
}


// DSU by size
void union_by_size(int x,int y,vector<int>& parent,vector<int> &rank){
    
}