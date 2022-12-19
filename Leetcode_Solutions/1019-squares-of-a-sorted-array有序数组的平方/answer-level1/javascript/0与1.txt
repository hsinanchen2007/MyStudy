`思路：使用双指针`

# 第一种

```
public int[] sortedSquares(int[] A) {
        int left = 0;
        int right = A.length - 1;
        int[] temp = new int[A.length];
        int currentIndex = right;
        while(left <= right){
            if(Math.abs(A[left]) <= Math.abs(A[right])){
                temp[currentIndex--] = (int)Math.pow(A[right],2);
                right--;
            }else{
                temp[currentIndex--] = (int)Math.pow(A[left],2);
                left++;
            }
        }
        return temp;
    }
```

# 第二种
```
public int[] sortedSquares(int[] A) {
        int left = 0;
        int right = A.length - 1;
        int[] temp = new int[A.length];
        int currentIndex = right;
        while(left <= right){
            int leftTemp = A[left];
            if(A[left] < 0){
                leftTemp = A[left] - A[left] * 2;
            }
            int rightTemp = A[right];
            if(A[right] < 0){
                rightTemp = A[right] - A[right] * 2;
            }
            if(leftTemp <= rightTemp){
                temp[currentIndex--] = A[right] * A[right];
                right--;
            }else{
                temp[currentIndex--] = A[left]*A[left];
                left++;
            }
        }
        return temp;
    }

    
```

# 第三种

```
// 先平方，再借助函数【排序】
    public int[] sortedSquares(int[] A) {
        for(int i =0;i<A.length;i++)
            A[i] = A[i]*A[i];
        
      Arrays.sort(A);
      
      return A;
    }
```


`2019年8月22日19:29:17`

```
/**
 * javaScript
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
  var count = A.length;
  var result = [];
  var lastnumber = 0;
  var i = 0, j = count -1;
  while(i <= j) {
    var leftnumber = Math.pow(A[i], 2);
    var rightnumber = Math.pow(A[j], 2);
    if (leftnumber > rightnumber) {
      result.unshift(leftnumber);
      i++;
    }else{
      result.unshift(rightnumber);
      j--;
    }
  }
  return result;
};
```