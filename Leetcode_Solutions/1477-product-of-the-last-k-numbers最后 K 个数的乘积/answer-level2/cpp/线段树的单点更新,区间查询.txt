用线段树水过去了,不知道大佬们肿么写的

```
#define ll long long int
#define MAXN ((int)40005)
ll tree[MAXN<<2], pn; //pn是当前有多少个数字
class ProductOfNumbers {
public:
    ll num, n;
    ProductOfNumbers() {
        pn = 0;
        n = 40002;
    }
    
    void push_up(int rt) {
        tree[rt] = tree[rt<<1] * tree[rt<<1|1];
    }
    
    void update(int rt, int lef, int rig) {
        // printf("%d-%d\n", lef, rig);
        if(lef == rig) {
            tree[rt] = num;
            return ;
        }
        int mid = (lef + rig) >> 1;
        if(pn<=mid) update(rt<<1, lef, mid);
        else update(rt<<1|1, mid+1, rig);
        push_up(rt);
    }
    
    void add(int num) {
        this->num = num;
        pn ++;
        update(1, 1, n);
    }
    
    int L, R;
    ll query(int rt, int lef, int rig) {
        // if(L<=lef && rig<=R) return tree[rt];
        if(L<=lef && rig<=R) return tree[rt];
        int mid = (lef + rig) >> 1;
        ll ret = 0, lsum = 0, rsum = 0;
        if(L <= mid) lsum = query(rt<<1, lef, mid);
        if(mid < R) rsum = query(rt<<1|1, mid+1, rig);
        if(L<=mid && mid<R) return lsum*rsum;
        else if(L<=mid) return lsum;
        else if(mid<R) return rsum;
        return ret;
    }
    
    int getProduct(int k) {
        L = pn - k + 1, R = pn;
        // printf("%d , %d\n", L, R);
        return query(1, 1, n);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

```
