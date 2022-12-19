### 解题思路
此处撰写解题思路
    设每个数组 首个为 n,数组长度为 (i+1) 则：
    n+n+1 = target
    n+n+1+n+2 = target
    n+n+1+n+2+n+3 = target
    所以规律为 (i+1)*n +1+2+3+……+i = target
    等差数列公式替换下即：
    (i+1)*n+(i+1)*(i)/2 = target

    所以 每个数组首项为 n= (target-(i+1)*i/2)/(i+1); 
    i从 1 开始自加 判断  (target-(i+1)*(i)/2)%(i+1)==0即可。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {

        List<int[]> list = new ArrayList<>();
       int i=1;
        while(true){

            if(check(target,i)){
                int begin = (target-(i+1)*i/2)/(i+1);

                if(begin<=0) break;

                int[] a = new int[i+1];
                for(int j = 0;j< a.length;j++){
                    a[j] = begin++;
                }
                list.add(a);
            }
            
        

            
            i++;

           
            
        }
        Collections.reverse(list);
        int[][] res = new int[list.size()][];

        for(int j = 0;j<list.size();j++){
            res[j] = list.get(j);
        }      

        return res;
    }

    boolean check(int target,int i){
        int sum = (i+1)*i/2;
        // int begin = (target-(i+1)*i/2)/(i+1);
        return (target-sum)%(i+1)==0;
    }
}
```