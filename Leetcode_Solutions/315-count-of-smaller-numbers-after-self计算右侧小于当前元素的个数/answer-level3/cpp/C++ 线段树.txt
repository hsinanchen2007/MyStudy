## 思路 线段树
时间复杂度：$O(N·LOG(N))$
空间复杂度：$O(N)$

## 代码

### 递归+动态内存

```cpp
class Node {
public:
    Node *l, *r;
    int lv, rv, sum;
    Node(int il, int ir) {
        l = NULL;
        r = NULL;
        lv = il;
        rv = ir;
        sum = 0;
    }
};

void ClearNode(Node *root) {
    stack<Node*> qn;
    qn.push(root);
    while (!qn.empty()) {
        auto p = qn.top();
        qn.pop();
        if (p->l)
            qn.push(p->l);
        if (p->r)
            qn.push(p->r);
        delete p;
    }
}

void insert(Node *root, int x)
{
    //cout << __func__ << ":" << x << endl;
    //cout << root->lv << ":" << root->rv << endl;
    root->sum++;
    if (root->lv == root->rv) {
        return;
    }
    int half = (root->lv + root->rv);
    if (half < 0)
        half = (half - 1) / 2;
    else
        half /= 2;
    if (x <= half) {
        if (!root->l)
            root->l = new Node(root->lv, half);
        insert(root->l, x);
    } else {
        if (!root->r)
            root->r = new Node(half + 1, root->rv);
        insert(root->r, x);
    }
}

int search(Node *root, int x, int y)
{
    //cout << __func__ << ":" << x << ":" << y << endl;
    int ret = 0;
    if (x <= y) {
        if (root->lv >= x && y >= root->rv)
            ret = root->sum;
        else {
            int half = (root->lv + root->rv);
            if (half < 0)
                half = (half - 1) / 2;
            else
                half /= 2;
            //cout << half << endl;
            if (x <= half && root->l)
                ret += search(root->l, x, min(half, y));
            if (y >= half + 1 && root->r)
                ret += search(root->r, max(half + 1, x), y);
        }
    }
    return ret;
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int size = nums.size();
        if (!size)
            return {};
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < size; i++) {
            if (nums[i] < min)
                min = nums[i];
            if (nums[i] > max)
                max = nums[i];
        }
        auto *root = new Node(min, max);

        vector<int> ret(size);
        for (int i = size - 1; i >=0; i--) {
            ret[i] = search(root, min, nums[i] - 1);
            insert(root, nums[i]);
        }

        ClearNode(root);

        return ret;
    }
};
```

### 非递归+数组

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        int min = nums[0];
        int max = nums[0];
        for (auto it = nums.begin() + 1; it != nums.end(); it++) {
            if (*it < min)
                min = *it;
            else if (*it > max)
                max = *it;
        }
        const int vsz = (max - min) * 4 + 2;
        const int nsz = nums.size();
        vector<int> count(vsz, 0);
        vector<int> ret(nsz);

        auto query = [&](int x) -> int {
            //cout << "query:" << x << endl;
            int ret = 0;
            int index = 1;
            int a = min;
            int b = max;
            if (x < min)
                return 0;
            while (a != b) {
                int xx = b + a;
                if (xx < 0)
                    xx--;
                auto half = xx / 2;
                if (x <= half) {
                    b = half;
                    index = 2 * index;
                } else {
                    a = half + 1;
                    ret += count[2 * index];
                    index = 2 * index + 1;
                }                
            }
            ret += count[index];
            return ret;
        };
        auto add = [&](int x) -> void {
            //cout << "add:" << x << endl;
            int a = min;
            int b = max;
            int index = 1;
            while (a != b) {
                //cout << a << "," << b << "," << index << endl;
                count[index]++;
                int xx = b + a;
                if (xx < 0)
                    xx--;
                auto half = xx / 2;
                //cout << half << endl;
                if (x <= half) {
                    b = half;
                    index = 2 * index;
                } else {
                    a = half + 1;
                    index = 2 * index + 1;
                }
            }
            count[index]++;
        };
        for (int i = nsz - 1; i >= 0; i--) {
            ret[i] = query(nums[i] - 1);
            add(nums[i]);
        }
        return ret;
    }
};
```