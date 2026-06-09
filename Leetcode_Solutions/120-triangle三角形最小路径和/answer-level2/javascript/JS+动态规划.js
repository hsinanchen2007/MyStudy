
![120.三角形最小路径和.png](https://pic.leetcode-cn.com/6784bb624ddebe610c6deb1ec6213b25457631bc8129188c95cd7d5f28777d39-120.%E4%B8%89%E8%A7%92%E5%BD%A2%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C.png)

![120.三角形最小路径和.jpg](https://pic.leetcode-cn.com/4438c75b3d0f25d2fc28dbc8230d0f80c319ea05bcc5401fd24dcd43513e7fe1-120.%E4%B8%89%E8%A7%92%E5%BD%A2%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C.jpg)

```
/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    let m = triangle.length;
    if(m == 0){
        return 0;
    }

    let temp = new Array(m);
    for(let i=0;i<m;i++){
        temp[i] = new Array(triangle[i].length);
    }

    temp[0][0] = triangle[0][0];
    for(let i=1;i<m;i++){
        temp[i][0] = temp[i-1][0] + triangle[i][0];
        let length = temp[i].length-1;
        temp[i][length] = temp[i-1][temp[i-1].length-1] + triangle[i][length];
    }

    for(let i=2;i<m;i++){
        for(let j=1;j<temp[i].length-1;j++){
            temp[i][j] = Math.min(temp[i-1][j-1],temp[i-1][j]) + triangle[i][j];
        }
    }
    console.log(temp);
    return Math.min(...temp[temp.length-1]);
};
```

