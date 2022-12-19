```
struct node
{
  node* one;
  node* zero;

  node() {
    one = nullptr;
    zero = nullptr;
  }
};

class Solution {
private:
  void insert(node* root, int num) {
    auto n = root;
    for (int i = 30; i >= 0; i--)
    {
      bool is_one = (num >> i) & 1; // 得到当前位是否为1
      if (is_one) {
        if (n->one == nullptr) {
          n->one = new node();
        }
        n = n->one;
      }
      else {
        if (n->zero == nullptr) {
          n->zero = new node();
        }
        n = n->zero;
      }
    }
  }

  int search(node* root, int num) {
    auto n = root;
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
      // 从最高位开始到最低位开始检测
      bool is_one = (num >> i) & 1;// 检测当前位是否为1
      if (is_one) {
        // 当前位为1
        // 如果当前位有为0的 切换到这个分支 因为这样可以让当前异或之后可以使得最高位值为1 使得结果最大
        if (n->zero) {
          n = n->zero;
          res += (1 << i);
        }
        else {
          // 只有相同的
          n = n->one;
        }
      }
      else {
        // 当前位为0
        // 如果当前位有为1的 切换到这个分支 因为这样可以让当前异或之后可以使得最高位值为1 使得结果最大
        if (n->one) {
          n = n->one;
          res += (1 << i);
        }
        else {
          // 只有相同的
          n = n->zero;
        }
      }
    }
    return res;
  }
public:
  int findMaximumXOR(vector<int>& nums) {
    auto root = new node();
    for (auto num : nums) {
      insert(root, num);
    }

    int max_val = 0;
    for (auto num : nums) {
      max_val = max(max_val, (search(root, num)));
    }
    return max_val;
  }
};
```

还有就是借鉴了一下其他大佬的使用位运算进行操作的算法，注意要用hash set...一开始用的set（红黑树实现的）最后一个用例会TLE...

下面附上代码

```
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    int mask = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
      mask = mask | (1 << i);
      unordered_set<int>sets; //这里我试过用set,会tle。。。 hash查找牛逼！！毕竟O(1)
      for (auto num : nums) {
        sets.insert(num & mask);
      }

      int temp = res | (1 << i);
      for (auto it : sets) {
        if (sets.find(it ^ temp) != sets.end()) {
          res = temp;
          break;
        }
      }
    }
    return res;
  }
};
```

