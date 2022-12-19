```
impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut vec:Vec<i32> = Vec::new();
        let mut result:f64 = 0.0;
        for num in nums1.iter() {
        	vec.push(*num);
        }
        for num in nums2.iter(){
        	vec.push(*num);
        }
        vec.sort();

        if vec.len()%2 != 0 {
        	result =  vec[(vec.len()-1)/2] as f64;
        }
        else{
        	result =  ((vec[vec.len()/2]+vec[vec.len()/2-1]) as f64)/2.0;
        }
        result
    }
}
```
