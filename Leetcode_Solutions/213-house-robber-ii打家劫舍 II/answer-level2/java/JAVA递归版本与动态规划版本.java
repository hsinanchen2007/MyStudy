![image.png](https://pic.leetcode-cn.com/1ecadeb40eb66a133bdfde32365cdea7602c15239bca164149ffff406a924afd-image.png)

class Solution {
    public final int rob(int[] nums) {
        if(nums==null){return 0;}
        int size=nums.length;
        if(size==0){return 0;}
        if(size==1){return nums[0];}
        if(size==2){return Math.max(nums[0],nums[1]);}
        if(size==3){return max(nums[0],nums[1],nums[2]);}
        int[] hasE=new int[size-1];
        System.arraycopy(nums,1,hasE,0,size-1);
        int[] cache1=new int[size-1];
        int[] cache2=new int[size-1];
        return Math.max(rob1(hasE,size-2,cache1),rob1(nums,size-2,cache2));
    }
    
    public final int rob1(int[] nums,int point,int[] cache){
        //递归版本开始
        // if(point==-1){return 0;}
        // if(point==0){return nums[0];}
        // if(point==1){return Math.max(nums[0],nums[1]);}
        // if(point==2){return Math.max(nums[0]+nums[2],nums[1]);}
        // if(cache[point]==0){
        //     cache[point]=max(rob1(nums,point-1,cache),rob1(nums,point-2,cache)+
        //                      nums[point],rob1(nums,point-3,cache)+nums[point]);
        // }
        // return cache[point];
        //递归版本结束
        
        //动态规划版本开始
        cache[0]=nums[0];
        cache[1]=Math.max(nums[0],nums[1]);
        cache[2]=Math.max(nums[0]+nums[2],nums[1]);
        for(int i=3;i<=point;i++){
            cache[i]=max(cache[i-1],cache[i-2]+nums[i],cache[i-3]+nums[i]);
        }
        return cache[point];
        //动态规划版本结束
    }
    
    public final int max(int a,int b,int c){
        int max=0;
        if(a>max){max=a;}
        if(b>max){max=b;}
        if(c>max){max=c;}
        return max;
    }
    
    public final int max(int a,int b,int c,int d){
        int max=max(a,b,c);
        if(max>d){return max;}
        return d;
    }
}
