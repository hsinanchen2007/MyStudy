# 想法
1. 规律
记函f(n)，表示当n个数相邻，并且两两拼接的数都大于9，小于26时，拥有的密码数：（记住一定是9，因为像“06”这种只有一种密码）
f(1) = 1
f(2) = 2
f(3) = 3
f(4) = 5
看出来是 斐波那契额数列了吧 哈哈

2. 做法
从后往前扫num，每次查找能够两两拼接满足>9 && <26的最长长度n，之后就可以把num遍历完。然后把每次的长度带入f(n),之后累乘即可。

3. 算法
算法中使用list来存储斐波那契额数列的值，用为字典。
```
class Solution {
    ArrayList<Integer> list = new ArrayList<>();
    public int translateNum(int num) {
        list.add(0);
        list.add(1);
        list.add(2);
        int res =1, loop = 1;
        while(num !=0){
            int two = num % 100;
            if(two > 9 && two<26) loop++;
            else {
                res *= f(loop);
                loop = 1;
            }
            num /= 10;
        }
        res *= f(loop);
        return res;
    }

    int f(int n){
        int len = list.size();
        while(len<=n){
            list.add(list.get(len-2)+list.get(len-1));
            len++;
        }
        return list.get(n);
    }
}
```
