```
public int[] plusOne(int[] digits) {
        for(int i=digits.length-1;i>=0;i--){
            if(digits[i]==9){//此位为9，需要进位
                digits[i]=0;
                continue;
            }
            if(digits[i]!=9){
                digits[i]+=1;
                break;
            }
        }

        int[] ans=new int[digits.length+1];
        ans[0]=1;
        if(digits[0]==0)return ans;
        else return digits;
    }
```



![TIM截图20191113112910.png](https://pic.leetcode-cn.com/df5ae5ee1ec2be1f238c953e8de19110f232dbfddedacac8d345deb9f572c309-TIM%E6%88%AA%E5%9B%BE20191113112910.png)

