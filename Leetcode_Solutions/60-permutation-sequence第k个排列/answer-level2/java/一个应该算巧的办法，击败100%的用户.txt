### 解题思路
击败100%的用户，开心！！耗时1ms
我举例子啊
比如n=4，k=15
n-1!=6意味着对于1,2,3,4开头的随机组合每一个组合都有六位
如1：（1,2,3,4）（1,2,4,3）（1,3,2,4）（1,3,4,2）（1,4,2,3）（1,4,3,2）
那么k=15意味着他应该是3开头的，然后15-6*2=3；
那么，对于数组1,2,4来说随机组合每组有2个组合
如1:(1,2,4)(1,4,2)
k=3意味着第二位应该等于2；
。。。。
以此类推
### 代码

```java
class Solution {
    private int Getfactorial(int x){
        int res=1;
        for(int i=x;i>=1;i--){
            res*=i;
        }
        return res;
    }
    public String getPermutation(int n, int k) {
        int dom=0,index=1,q=0,tmp=0;
        int[] Mask=new int[n];
        String res="";
        for(int i=0;i<n;i++) {
            Mask[i] = i + 1;
        }
        for(int i=0;i<n;i++){
            dom=Getfactorial(n-i-1);
            while(index*dom<k){
                index++;
            }
            tmp=index;
            for(q=0;index>1||Mask[q]==0;q++){
                if(Mask[q]!=0)
                    index--;
            }
            res+=Mask[q];
            Mask[q]=0;
            k-=dom*(tmp-1);
        }
        return res;
    }
}
```