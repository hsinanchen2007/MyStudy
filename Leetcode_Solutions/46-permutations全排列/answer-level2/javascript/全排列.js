### 解题思路
分解代码：
swap(): 数组元素位置交换
perm(): 递归函数

思路：可以抽象成树结构
    for i=p
    1.先遍历数组，分别把数组的每一项（i项）都与第一项（需要排列的第一项q）位置交换，这是第一层。
    2.在第一层结果的基础上，继续把数组每一项（p+1）都与第一项（需要排列的第一项q）位置交换，以此类推。
    3.每一个递归函数在p=q的时候，已经递归到最后一项，就是一种结果。


### 代码

```javascript
    function swap(arr,i,j) {
        [arr[i],arr[j]] = [arr[j],arr[i]]
    }
    function perm(arr,p,q,res) {
        if(p == q) {
            res.push([...arr])
        }else{
            for(let i=p;i<q;i++) {
                swap(arr,p,i)
                perm(arr,p+1,q,res)
                swap(arr,p,i)
            }
        }
    }
    var permute = function(nums) {
        let res = []
        perm(nums,0,nums.length,res)
        return res
    };
```