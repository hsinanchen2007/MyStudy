方法1：哈希表记录每一次运算的结果 通过判断下一次运算得到的结果是不是之前已经存在于表中来判断循环

这种方法不是很好，效率低&占用空间大，尤其是在碰到循环周期特别长的数字时候尤其明显。

```
class Solution {
public:
    bool isHappy(int n) {
        
        map<int, int> map = {
            {0,0},{1,1},{2,4},
            {3,9},{4,16},{5,25},
            {6,36},{7,49},{8,64},
            {9,81}
        };
        
        int new_key = n;
        int temp1 = new_key;

        while(true){
        
            int temp3 = 0;
            
            while(temp1>0){
            
                int temp2 = temp1%10;
                temp3 += map[temp2];
                temp1 /= 10;
            }
            
            map[new_key] = temp3;
            
            if(map[new_key]==1){
                return true;
            }

            new_key = map[new_key];
            
            if(new_key==0 ||(new_key >9 && map[new_key]>0))
                return false;
            
            temp1 = new_key;
            
        }


        return false;
    }
};
```

方法2：快慢指针法

思路是无论是不是快乐数，只要按照规矩去计算都是会陷入无止境的循环的。

那么，我们可以判断这个循环是不是由1^2==1引起的。

```
class Solution {
public:
    
    int next_num(int num){
        
        //获取原数字按每个位置上的数字平方和后的新数字（利用数组节省平方的运算（然而好像节省不了多少...
        int a[10] = {0,1,4,9,16,25,36,49,64,81};
        int new_num = 0;
        
        while(num>0){
            
            int temp2 = num%10;
            new_num += a[temp2];
            num /= 10; 
        }
        
        return new_num;
    }
    
    bool isHappy(int n) {
        
        //快慢指针法
        int slow = n;
        int fast = next_num(n);
        
        while(slow!=fast){
            
            slow = next_num(slow);
            fast = next_num(fast);
            fast = next_num(fast);
        }
        
        return slow==1;

    }
};
```
