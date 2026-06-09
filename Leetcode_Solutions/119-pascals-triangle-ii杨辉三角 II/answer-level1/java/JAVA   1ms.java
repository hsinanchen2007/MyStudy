参考windliang的题解，因为杨辉三角是对称的，所以前一半计算，后一半翻转复制前一半。

```
class Solution {
    public List<Integer> getRow(int rowIndex) {
    List<Integer> ans = new ArrayList<>();
    long pre = 1;
    ans.add(1);
    if(rowIndex == 0)
    return ans;
    for (int k = 1; k < (rowIndex+1)/2; k++) {
        long cur = pre * (rowIndex - k + 1) / k;
        ans.add((int) cur);
        pre = cur;
    }
    if(rowIndex%2==0){
        long cur = pre * (rowIndex - rowIndex/2 + 1) /(rowIndex/2);
        ans.add((int) cur);
    }
    for (int k = (rowIndex+1)/2-1; k >=0; k--) {
        ans.add(ans.get(k));
    }
    return ans;
}
} 
```

