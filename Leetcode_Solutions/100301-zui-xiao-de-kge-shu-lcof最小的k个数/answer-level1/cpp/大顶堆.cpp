### 解题思路
此处撰写解题思路

### 代码

```cpp
class heap {
public:
    vector<int> hp;
    int num;
    heap(vector<int> a) {
        hp = a;
        num = hp.size();
        for (int i = father(num - 1); i >= 0; i--) {
            sink(i);
        }
    }
    /*int pop() {
        swap(0, num - 1);
        num--;
        sink(0);
        return hp[num];
    }*/
    void push(int a) {
        if (a < hp[0]) {
            hp[0] = a;
            sink(0);
        }
    }
    inline int father(int a) {
        return (a-1) / 2;
    }
    inline int leftchild(int a) {
        return 2*a + 1;
    }
    inline int rightchild(int a){
        return 2 * a + 2;
    }
    void sink(int a) {
        int temp;
        int i;
        i = a;
        while (leftchild(i) < num) {
            if (rightchild(i) >= num) {
                temp = leftchild(i);
            }
            else if (hp[leftchild(i)] > hp[rightchild(i)]) {
                temp = leftchild(i);
            }
            else temp = rightchild(i);
            if (hp[i] < hp[temp]) {
                swap(i, temp);
                i = temp;
            }
            else break;
            
        }
    }
    void swap(int a, int b) {
        int temp;
        temp = hp[a];
        hp[a] = hp[b];
        hp[b] = temp;
    }
};
 
 class Solution {
 public:
     vector<int> getLeastNumbers(vector<int>& arr, int k) {
         vector<int> res(arr.begin(),arr.begin()+k);
         if (k == 0)
             return res;
         heap h(res);
         for (int i = k; i < arr.size(); i++) {
             h.push(arr[i]);
         }
         return h.hp;
     }
 };
```