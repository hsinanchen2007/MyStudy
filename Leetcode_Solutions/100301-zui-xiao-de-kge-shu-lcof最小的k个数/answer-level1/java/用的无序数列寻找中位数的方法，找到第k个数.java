### 解题思路
此处撰写解题思路

### 代码

```java
  class Solution 
  {

       public static void swap(int[] a, int i, int j){
        int temp = a[i];
        a[i] =  a[j];
        a[j] = temp;
    }

    int qicSort(int[]arr,int s,int e) {
        int v = arr[s];
        int i = s, j = e + 1;
        while (true) {
            while (++i <= e && arr[i] < v);
            while (--j >= s && arr[j] > v);
            if (i >= j) {
                break;
            }
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
        arr[s] = arr[j];
        arr[j] = v;
        return j;
    }
    int[] outputArr(int[] a,int k,int i,int j)
    {
        int key=qicSort(a,i,j);
        if(key==k)
        {return Arrays.copyOf(a,key+1);}
        if(k<key)
         return    outputArr(a,k,i,key-1);
        if(k>key)
          return   outputArr(a,k,key+1,j);
        return new int[0];
    }

    public int[] getLeastNumbers(int[] arr, int k)
    {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
      return   outputArr(arr,k-1,0,arr.length-1);
    }
  }
```