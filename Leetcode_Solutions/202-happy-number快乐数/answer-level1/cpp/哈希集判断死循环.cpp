正好是在学习哈希集时看到的，故用哈希集解决本题。
关键就是利用哈希集判断是否存在重复元素以此判断是否陷入死循环。
```
class Solution {
public:
    int bitSquareSum(int num){
        int sum=0;
        do{
            sum += (num%10)*(num%10);
            num /= 10;
        }while(num != 0);
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n != 1){
            n=bitSquareSum(n);
            if(set.count(n)>0)
                return false;
            set.insert(n);
        }
        return true;
    }
};
```
