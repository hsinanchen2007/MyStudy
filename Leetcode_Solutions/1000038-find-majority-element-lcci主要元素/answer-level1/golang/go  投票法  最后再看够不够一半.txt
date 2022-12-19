### 解题思路
此处撰写解题思路
投票法  最后再看够不够一半
### 代码

```golang
func majorityElement(nums []int) int {
    if (len(nums) == 0) {
        return -1
        }
    count := 1
    person := nums[0]
    for i := 1; i < len(nums); i++ {
        if (person == nums[i]) {
            count++;
        }else{
            count--
        }
        if (count == 0) {
            person = nums[i];
            count=1
        } 
    }
    // 验证是否超过一半
    count = 0;
    for _, v := range nums {
        if (person == v) {
            count++;
        }
    }
    if count > len(nums)/2 {
        return person;
    }
    return -1;
}
```