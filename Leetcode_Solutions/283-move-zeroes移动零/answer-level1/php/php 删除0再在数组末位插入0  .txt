
![图片.png](https://pic.leetcode-cn.com/65095ae8c06a5305c6fdb316de345184cb349aab17f30444f54724b5ec2eeafb-%E5%9B%BE%E7%89%87.png)

```
function moveZeroes(&$nums) {
        for($i=0;$i<count($nums);$i++){
            if($nums[$i] == 0){
                unset($nums[$i]);
                array_push($nums,0);
            }
        }
        return $nums;
    }
```
