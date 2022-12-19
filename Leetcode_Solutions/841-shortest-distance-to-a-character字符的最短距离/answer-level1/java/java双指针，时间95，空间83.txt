
```
class Solution {
  //此题最终需要比较离左边还是右边的更小，才是答案，最大不超过数组长度
  public int[] shortestToChar(String S, char C) {
    char[] array=S.toCharArray();
    int[] result = new int[array.length];
    int[] left = new int[array.length];
    int[]  right= new int[array.length];
    left[0]=array[0]==C?0:array.length;//第一个特殊处理
    for (int i=1;i<array.length;i++){
      left[i]=array[i]==C?0:left[i-1]+1;
    }
    right[array.length-1]=array[array.length-1]==C?0:array.length;
    for (int i=array.length-2;i>=0;i--){
      right[i]=array[i]==C?0:right[i+1]+1;
    }
    for (int i=0;i<array.length;i++){
      result[i]=Math.min(left[i],right[i]);
    }
    return result;
  }
```

}