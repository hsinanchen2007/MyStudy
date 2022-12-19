```
impl Solution {
    pub fn find_repeat_number(nums: Vec<i32>) -> i32 {
        
        if nums.len() == 0 {
            return -1;
        }
        
        for i in 0..nums.len(){
            if nums[i] < 0 || nums[i] >= nums.len() as i32{
                return -1;
            }
        }
        
        let mut t = nums.clone();
        let mut res = 0;
        
        for i in 0..nums.len(){
            
            while(i != t[i] as usize){
                let tmp = *&t[i] as usize;
                
                if (t[i] == t[tmp]){
                    res = t[i];
                    break;
                }
                // swap t[tmp] and t[i]
                let temp = t[tmp];
                t[tmp] = t[i];
                t[i] = temp;
            }
        
        }
        res
    }
}
```