### 解题思路
此处撰写解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.5 MB, 在所有 Java 提交中击败了5.97%的用户

能用Greedy关键在于本题中所有的解最后的目标值都是一样的；（官方第二种那个球的拓扑图解释了为什么）；
那么只需要依次记录每个数的位置（site[]  占用空间O[n]）；
当碰到一个数i，其配对的数p已经出现了，就把i现在配对的数（i-1或i+1）与p对调即可。
这样只便利一次数组时间O[n]
### 代码

```java
class Solution {
    public int minSwapsCouples(int[] row) {
        int n=0;
       
        int len=row.length;
        int[]site=new int[len];
        for(int i=0;i<len;i++){
             site[i]=-1;
        } 
    
        int s1=0;
        int s11=0;
        int r=0;
        int s=0;
        int d=0;
        for(int i=0;i<len;i++){ 
             s1=row[i];
             if(site[s1]!=-1){
                site[s1]=i;
             }
       	    
             if(s1%2==0){
                s11=s1+1;
             }else{
                s11=s1-1; 
             }
     
             r=i%2;
                      
             if(site[s11]!=-1&site[s11]<i-r){
                 s=site[s11];
                 // 找与s11配对的那个；
            	 if(s%2==0){
            		 s=s+1;
            	 }else {
            		 s=s-1;
            	 }//*/
                 d=row[i];
            	  row[i]=row[s];
            	  row[s]=row[i];
                 site[s1]=s;
                 site[row[s]]=i; 	
            	 n++;
             }
             
          
             
          }
       
     return n;        
    }
}
```