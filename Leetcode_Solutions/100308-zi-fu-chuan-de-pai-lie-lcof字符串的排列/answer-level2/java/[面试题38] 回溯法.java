### 解题思路
交换法

### 代码

```java
class Solution {
    private ArrayList<String> ans = new ArrayList<String>();
    public String[] permutation(String s) {
        char [] arrs = s.toCharArray();
        traceback(arrs,0);
        return ans.toArray(new String[ans.size()]);
    }

    public void traceback(char [] arrs,int index){
        if(index == arrs.length){
            ans.add(new String(arrs));
            return;
        }
        for(int i = index;i<arrs.length;i++){
            boolean same = false;
            for(int j = index;j<i;j++){ //去重
                if(arrs[j] == arrs[i]){
                    same = true;
                    break;
                }
            }
            if (same){
                continue;
            }
            swap(arrs,index,i);
            traceback(arrs,index+1);
            swap(arrs,index,i);
        }
    }
    public void swap(char [] arrs,int i,int j){
        char t = arrs[i];
        arrs[i] = arrs[j];
        arrs[j] = t;
    }
}
```