可以使用线段树来做。比较直接。

typedef long long ll;

struct no{
    ll value;
    int position;

    bool operator < (const no &other){
        return value < other.value;
    }
};

struct segtree{
    int l;
    int r;
    int sum;
};

const int MAXN = 50000 + 5;
segtree tree[4 * 2 * MAXN];

int after_discretization[MAXN];
int after_discretization_double[MAXN];
no twice[MAXN * 2];

void build(int i, int x, int y){
    if( x > y )return;
    tree[i].l = x;
    tree[i].r = y;
    tree[i].sum = 0;

    if( x == y ) return;

    int lch = i + i, rch = i + i + 1, m = (x + y) >> 1;

    build(lch, x, m);
    build(rch, m+1, y);
}

void insert(int i, int x){
    if(tree[i].l == tree[i].r && tree[i].l == x){
        tree[i].sum += 1;
        return;
    }

    int lch = i + i, rch = i + i + 1, m = (tree[i].l  + tree[i]. r) >> 1;

    if(x <= m)insert(lch, x);
    else insert(rch, x);

    tree[i].sum = tree[lch].sum + tree[rch].sum;
}

int query(int i, int x, int y){
    if(tree[i].l >= x && tree[i].r <= y){
        return tree[i].sum;
    }

    int ret = 0;

    int lch = i + i, rch = i + i + 1, m = (tree[i].l  + tree[i]. r) >> 1;
    if(x<=m)ret += query(lch, x, y);
    if(y>m)ret += query(rch, x, y);

    return ret;
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {

        int len = nums.size();
        for(int k=0;k<len;k++){

            ll value = nums[k];

            twice[k] = (no){value, k};
            twice[k + len] = (no){value * 2 + 1, k + len};
        }  // Record the original array and doubled one.

        sort(twice, twice + 2*len);

        int k = 0;

        for(int i = 0; i < 2 * len; i++){
            if(i==0 || twice[i].value != twice[i-1].value)k++;
            if(twice[i].position >= len){after_discretization_double[twice[i].position - len] = k;}
            else after_discretization[twice[i].position] = k;
        }

        build(1, 1, k);

        int ans = 0;

        for(int i = 0;i < len; i++){
            ans += query(1, after_discretization_double[i], k);
            insert(1, after_discretization[i]);
        }

        return ans;
    }
};

But是否可以用改造后的归并排序做就不得而知了。