### 解题思路
时间复杂度为O(n),所以只能用一个for（）遍历，维护a,b,c保证他们由大到小依次比较，如果比c大插入,如果比b大，再往前插入，如果比a大再往前，若是重复则回退，并丢弃它。

### 代码

```java
class Solution {
    public int thirdMax(int[] nums) {
		int num = nums.length;
		int a=Integer.MIN_VALUE;
        int b=a;
        int c=a;
        int tempb=0,tempc=0;
        boolean flaga=false;
		if(num==1){return c=nums[0];}
		else if(num==2) {return c=Math.max(nums[0], nums[1]);}
        else{
        for(int i=0;i<num;i++){
        	if(nums[i]>=c){
                tempc=c;
                c=nums[i];
                if(nums[i]==Integer.MIN_VALUE){flaga=true;}
                if(nums[i]==b){
                    c=tempc;
                }
                if(nums[i]>b){
                    c=b;
                    tempb=b;
                    b=nums[i];
                    if(nums[i]==a){
                        c=tempc;
                        b=tempb;
                    }
                    if(nums[i]>a){
                        c=tempb;
                        b=a;
                        a=nums[i];
                    }
                    
                }
        	}
        }
        }
        if(c==Integer.MIN_VALUE && flaga!=true || b==Integer.MIN_VALUE ){
            return a;
        }
        return c;
    }
}
```