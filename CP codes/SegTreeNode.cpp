struct node{
  int open=0;
  int close=0;
  int full=0;
};
class Segtree{
    public:
    vector<node>tree;
    Segtree(string &a){
        
        int n= (int)a.size();
        tree.resize(4*n+1);
    }
     void build(string &a,int x, int left, int right){
        if(right==left){
          
          if(a[right]=='('){
            tree[x].open++;
          }
          else tree[x].close++;
            return;
        }
        int mid= (right+left)/2;
        build(a,2*x+1,left,mid);
        build(a,2*x+2,mid+1,right);
        tree[x].full= tree[2*x+1].full+tree[2*x+2].full+ min(tree[2*x+1].open, tree[2*x+2].close);
        tree[x].open= tree[2*x+1].open-min(tree[2*x+1].open, tree[2*x+2].close)+tree[2*x+2].open;
        tree[x].close= tree[2*x+1].close-min(tree[2*x+1].open, tree[2*x+2].close)+tree[2*x+2].close;
        
    }
   
    // void set(int i,int v,int x, int left, int right,bool xo ){
    //     if(right == left){
    //         tree[x]= v;
    //         return;
    //     }
    //     int mid = (right+left)/2;
    //     if(i<=mid){
    //         set(i,v,2*x+1,left,mid,!xo);
    //     }
    //     else set(i,v,2*x+2,mid+1,right,!xo);
        
    //     if(xo)tree[x]= tree[2*x+1]^tree[2*x+2];
    //     else tree[x]= tree[2*x+1]|tree[2*x+2];
    // }
    node mini(int l,int r,int x,int left, int right){
        if(r<left||l>right){
          node p;
            return p ;
        }
        if(left>=l&&right<=r){
            return tree[x];
        }
        else{
            int mid = (left+right)/2;
            node a= mini(l,r,2*x+1,left,mid);
            node b= mini(l,r,2*x+2,mid+1,right);
            //return min(mini(l,r,2*x+1,left,mid),mini(l,r,2*x+2,mid,right));
            node ans;
            ans.full= a.full+b.full+ min(a.open,b.close);
        ans.open= a.open-min(a.open, b.close)+b.open;
        ans.close= a.close-min(a.open, b.close)+b.close;
 
            return ans;
        }
    }
    
  
};