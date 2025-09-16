//  DSU by Path Compression
int findParent(int node,vector<int>& parents){
    if(node==parents[node]){
        return node;
    }

    return parents[node]=findParent(parents[node],parents);
}

// DSU by rank
void union_by_rank(int x,int y,vector<int>& parents,vector<int>& ranks){
    int x_parent=findParent(x,parents);
    int y_parent=findParent(y,parents);

    if(x_parent==y_parent) return ;

    // if one's rank is more attach the less ranked one to the higher one to reduce the branching effect
    if(ranks[x_parent]>ranks[y_parent]){
        parents[y_parent]=x_parent;
    } else if(ranks[x_parent]<ranks[y_parent]){
        parents[x_parent]=y_parent;
    } else {
        parents[x_parent]=y_parent;  // if ranks are same for both make any one of them as parent and increase the parent's rank;
        ranks[y_parent]++;
    }

    return ;
}


// DSU by size
void union_by_size(int x,int y,vector<int>& parents,vector<int> &ranks){

}