这算是一道很经典的题目了。

朴素算法: 
针对每一对数进行xor运算， 找出其中最大的。
时间复杂度 $O(n^2)$ 无法通过此题。

优化算法：
考虑异或的性质。只有当两位不同的时候该位结果才为1. 因此针对某个特定的数， 如果我们能找出一个数和它配对产生最大值，举个最简单的例子。
假设有一数组[2,3,10,11], 转化为4位二进制则为[0010, 0011, 1010, 1011]
我们要找与2异或产生最大值的数， 则可以从首位开始。 
(1) 因为2的首位为0, 所以若首位有1的数， 则肯定最大, 其中[1010, 1011]满足;
(2) 因为2的次高位为0, 所以在(1)集合中且次高位为1，则在此步最大。没有这样的数， 保留[1010, 1011]
(3) 因为2的第三位为1, 所以在(2)集合中且次高位为0，则在此步最大。其中[1010, 1011]满足。
(4) 因为2的第四位为0, 所以在(2)集合中且次高位为1，则在此步最大。其中[1011]满足。结束。则 此处最大值 2 ^ 11 = 13.

很明显， 在此处可以用贪心的做法来做。 如果我们能把这些数用一种方式存储下来快速读取， 则可以做到。 显然前缀树可以做到。 因为我们每一次只关心这样的数是否存在， 而不关心具体是哪些。 所以可以共用数据空间来存储每一位上的数。

但是我对本题“线性”的说法持保留意见。 因为本题规定为32位整数， 则确实深度不过32， 可以当成常数。 然而一个数的位数与它的值为对数关系， 我不认为可以简单忽略。 （这样的话， 带范围限制的二分搜索也可看成线性， 显然不够科学）

时间复杂度 $O(nlogn)$ 
空间复杂度 $O(nlogn)$ 

```
struct node{
    node *zero;
    node *one;

    node(){
        zero = one = NULL;
    }
};



class Solution {
public:

    node *root;
    

    void add(node *root, int *value){
        node *cur = root;
        for(int i = 0; i < 32; i++){
            if(value[i] == 0){
                if(cur -> zero == NULL){
                    cur -> zero = new node();
                }

                cur = cur -> zero;
            }

            else{
                if(cur -> one == NULL){
                    cur -> one = new node();
                }

                cur = cur -> one;
            }
        }
    }

    int check(node *root, int value[32]){
        node *cur = root;
        int ret = 0;
        for(int i = 0; i < 32; i++){
            if(value[i] == 0){
                if(cur -> one != NULL){
                    ret += (1 << (31 - i));
                    cur = cur -> one;
                }

                else cur = cur -> zero;
            }

            else{
                if(cur -> zero != NULL){
                    ret += (1 << (31 - i));
                    cur = cur -> zero;
                }

                else cur = cur -> one;
            }
        }

        return ret;
    }

    int findMaximumXOR(vector<int>& nums) {
        root = new node();

        int n = nums.size();

        const int BITS = 32;

        int bin[BITS], tmp, best = 0;

        for(int i = 0; i < n; i++){
            int tmp = nums[i];
            for(int j = BITS - 1; j >= 0; j--){
                bin[j] = tmp % 2;
                tmp /= 2;

            }

            if(i > 0){
                int cur = check(root, bin);
                if(cur > best)best = cur;
            }

            add(root, bin);
        }

        return best;    
    }
};
```
