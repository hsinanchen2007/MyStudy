1.单纯为了爽的话可以直接暴力破解，遍历所有元素，但这题给的矩阵是有规律的
2.直接从右上角开始走，如果该元素小于target，则说明这一行都小于target，行++，行应该小于matrix.length
3.会有一行的末尾元素大于target，接着行不变，列--，列应该大于等于0
4.上述俩步中如果有某个元素等于target，返回true
5.如果这一行没有找到，行++，让列变为matrix【0】.length，即下一行的最后一个元素，重复2.3过程
6.最终遍历完毕没有找到的话，返回false，此方法大部分的元素都没有遍历到
```
var findNumberIn2DArray = function(matrix, target) {
    if(matrix.length ==0){
        return false;
    }
    //n为行，m为列
    let n  = matrix.length;
    let m = matrix[0].length;
    for(let i = 0;i<n;){
        if(matrix[i][m]<target){
            i++;
            continue;
        }else if(matrix[i][m] ==target){
            return true;
        }else{
            if(m>0){
                m--;
            }else{
                m = matrix[0].length;
                i++;
            }
        }
    }
    return false;
};
```
![QQ图片20200214165921.png](https://pic.leetcode-cn.com/038957dc14619624a80766126c7f015409cd8ab91b295fc53d3662082c31aa0c-QQ%E5%9B%BE%E7%89%8720200214165921.png)
