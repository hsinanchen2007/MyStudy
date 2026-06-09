主要思路如下：
1.报数不同的兔子颜色必定不同。
2.报数相同的兔子数量如果超过所报数字+1，则必定在同一报数中有多种颜色的兔子。

第一条比较好理解，这里就不解释了。详细解释一下第二条的意思，举例说明：

假设输入为{1,1,1,1}，第一只兔子为红色，
那么第2只兔子也可以是红色，此时第1只所指的另一只红色兔子就是第2只，而第2只所指的红色兔子即为第1只。
那么容易看出，第3、4只就不再可能是红色了。

基于此思路，实现过程如下：
1.对数组进行非降序排序
2.遍历数组：
    a.数字相同时，记录相同数字出现次数，当出现数字次数超过数字+1时，兔子数+=数字+1，数字出现次数清零
    b.数字不同时，数字出现次数清零，兔子数+=数字+1

代码如下：
```
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(),answers.end());
        int i=0;
        int counter=0;                              //用于记录兔子数量
        int count;                                  //用于记录报数相同的兔子数
        while(i<answers.size()){
            if(i>0 && answers[i]==answers[i-1]){    //当兔子报数与之前的兔子相同时
                ++count;
                if(count>answers[i]){               //如果报数相同的兔子数超过了所报数字
                    counter+=answers[i]+1;
                    count=0;                        //重新开始计数count
                }
            }
            else{                                   //当所报数字不同时，定是新颜色的兔子
                count=0;
                counter+=answers[i]+1;
            }
            ++i;
        }
        return counter;
    }
};
```
