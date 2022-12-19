```
    public void duplicateZeros(int[] arr) {
        int[] arr1=arr.clone();   //克隆一个相同的数组
        DFS(arr,arr1,0,0);
    }
    public void DFS(int[] arr,int [] arr1,int i,int j){ //写一个递归方法，i指针记录要改变的数组arr，j记录他的原版arr1指针
        if (i>=arr.length){                             //如果i到达边界，结束方法
            return;             
        }
        arr[i++] = arr1[j];                             //当前i指针arr等于j指针arr1的值
        if (arr1[j]==0&&i<arr.length) {                 //如果j指针的arr1等于0并且i没有越界，i的下一位也等于0；
            arr[i++] = arr1[j];
        }
        DFS(arr, arr1, i, j + 1);                       //调用下一位 j+1
    }
```
