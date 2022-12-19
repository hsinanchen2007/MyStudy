**其实,这可以直接用一个二维数组便很简单了，数组3x3就像下面一样**
a[0][0]这个元素没有什么影响
**数组中每个数都由它上一个数字和左边一个数字相加得到**
但可气的是javascript多维数组的定义不像其他语言一样那么直接,所以用了多次循环可能时间复杂度会大一点.

[[0,1,1],
 [1,2,3],
 [1,3,6]]

function uniquePaths(m,n){
    var arr = [];
    for(i=0;i<n;i++){
        arr[i]=[];
        for(j=0;j<m;j++){
            arr[i][j]=undefined;
        }
    }
    for(y=0;y<m;y++){
        arr[0][y]=1;
    }
    for(x=0;x<n;x++){
        arr[x][0]=1;
    }
    // console.log(arr)
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    // console.log(arr)
    return arr[n-1][m-1]
}