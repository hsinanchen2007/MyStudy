分解 A+B+C+D 为A+B和C+D，对A+B进行hash存储(最大250000个值)，遍历C+D时，从hash中搜索。

**执行用时 :52 ms, 在所有 java 提交中击败了99.91%的用户
内存消耗 :49.2 MB, 在所有 java 提交中击败了99.04%的用户**

### 代码

```java
class Solution {
    private static final int MOD = 500131;
    private static final int ADD = 1<<29;
    class HashNode{
        int val;
        int cnt;
        HashNode next;
        HashNode(int _val){
            val=_val;
            cnt = 1;
            next=null;
        }
    }

    HashNode[] hashbuck;
    int totalCnt;
    void addHashNode(int value){
        int index=(value+ADD)%MOD;
        HashNode newnode=new HashNode(value);
        newnode.next=hashbuck[index];
        hashbuck[index]=newnode;
    }

    HashNode searchHashNode(int value){
        int index=(value+ADD)%MOD;
        HashNode ref=hashbuck[index];
        while(ref!=null){
            if(ref.val == value) return ref;
            ref=ref.next;
        }
        return null;
    }

    void findHashNode(int value){
        int index=(value+ADD)%MOD;
        HashNode ref=hashbuck[index];
        while(ref!=null){
            if(ref.val == value){
                totalCnt+=ref.cnt;
                break;
            }
            ref=ref.next;
        }
    }
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int size=A.length;
        hashbuck = new HashNode[MOD];

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                int tmp=A[i]+B[j];
                HashNode ref=searchHashNode(tmp);
                if(ref==null){
                    addHashNode(tmp);
                }
                else{
                    ref.cnt++;
                }
            }
        }
        totalCnt=0;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++) {
                int tmp=0-(C[i]+D[j]);
                findHashNode(tmp);
            }
        }
        return totalCnt;
    }
}
```