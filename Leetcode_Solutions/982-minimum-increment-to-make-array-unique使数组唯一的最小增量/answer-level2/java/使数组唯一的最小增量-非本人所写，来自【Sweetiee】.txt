### 解题思路
我TM想复杂了。。。

### 代码

```java
//非本人所写，来自【Sweetiee】

class Solution {
    public int minIncrementForUnique(int[] A) {
        // counter数组统计每个数字的个数。
        //（这里为了防止下面遍历counter的时候每次都走到40000，所以设置了一个max，这个数据量不设也行，再额外设置min也行）
        int[] counter = new int[40001];
        int max = -1;
        for (int num: A) {
            counter[num]++;
            max = Math.max(max, num);
        }
        
        // 遍历counter数组，若当前数字的个数cnt大于1个，则只留下1个，其他的cnt-1个后移
        int move = 0;
        for (int num = 0; num <= max; num++) {
            if (counter[num] > 1) {
                int d = counter[num] - 1;
                move += d;
                counter[num + 1] += d;
            }
        }
        // 最后, counter[max+1]里可能会有从counter[max]后移过来的，counter[max+1]里只留下1个，其它的d个后移。
        // 设 max+1 = x，那么后面的d个数就是[x+1,x+2,x+3,...,x+d],
        // 因此操作次数是[1,2,3,...,d],用求和公式求和。
        int d = counter[max + 1] - 1;
        move += (1 + d) * d / 2;
        return move;
    }
}


/*以下是本人的答案，时间复杂度为O(n^2)，超时
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A.length==0)
            return 0;       
        int[][] b = new int[A.length][2];
        int catlog=0;
        int total=0;
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0;i<A.length;i++){
            list.add(A[i]);   
            b[i][1]=0;         
        }
        Collections.sort(list);
        b[0][0]=list.get(0);
        b[0][1]=1;
        for(int i=1;i<A.length;i++){
            if(list.get(i)!=list.get(i-1)){
                catlog++;
                b[catlog][0]=list.get(i);
            }
                b[catlog][1]++;
        }
        catlog+=1; /////////////////////important!!!
        int beforemax;
        int max = b[0][0];        
        for(int i=0;i<catlog;i++){          
            total+=(2*max-2*b[i][0]+b[i][1])*(b[i][1]-1)/2;
            beforemax=max;
            max+=b[i][1]-1;
            for(int j=i+1;j<catlog;j++){
                if(b[j][0]>max){
                    if(j==i+1)
                        max = b[j][0];
                    break;
                }                   
                else{
                    if(b[j][0]>=beforemax){/////////////
                        max++;
                        total+=(max-b[j][0]);                        
                    }
                }
            }
        }
        return total;
    }
}

*/
```