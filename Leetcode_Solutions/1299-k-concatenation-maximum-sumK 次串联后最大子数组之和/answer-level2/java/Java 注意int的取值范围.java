一开始没有注意int的取值范围在[2147483647,-2147483648]，大约是21亿，所以只通过前35个用例，最后两个死活过不去！

```
public int kConcatenationMaxSum(int[] arr, int k) {
        int len=arr.length;
        int[] sum=new int[len+1];//一定要多一位0，计算最大后缀和需要一个0
        int pre=0,post=0,iterAdd;
        int maxOne=0;
        long answer=0;
        sum[0]=0;
        for(int i=0;i<len;i++){
            sum[i+1]=arr[i]+sum[i];
            maxOne=Math.max(0,maxOne+arr[i]);
            if(maxOne>answer){
                answer=maxOne;
            }
        }
        if(k==1)return (int)answer;
        iterAdd=Math.max(0,sum[len]);
        for(int i=0;i<len;i++){
            pre=Math.max(pre,sum[i+1]);
            post=Math.max(post,sum[len]-sum[i]);
        }
        answer=Math.max(answer,(long)(k-2)*iterAdd+pre+post);//一定要用long
        return (int)(answer%1000000007);
    }
```
