### 解题思路
此处撰写解题思
两个中间变量a和b， b负责遍历数组，a负责记录去重后的数组位置。
### 代码

```golang
func removeDuplicates(nums []int) int {
    if (len(nums)==0) {
        return 0;
    };
    var  a int = nums[0];
    var b int;
    var i,j int = 0,0;
    for i = 0; i < len(nums); i++ {
        b = nums[i];
        if(b != a){
            j++;
            nums[j]=b;
            a = nums[j]
        }
    }
    return j+1;
}
```