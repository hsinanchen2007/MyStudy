```ruby []
def find_median_sorted_arrays(nums1, nums2)
    mid = 0
    nums = []
    k = (nums1.length + nums2.length)/2+1
    i=0;j=0 
    while ((i < nums1.length || j < nums2.length) && i+j < k)
        if i < nums1.length && j < nums2.length
            if nums1[i] < nums2[j]
                nums<<nums1[i]
                i+=1
            else
                nums<<nums2[j]
                j+=1
            end
        else
            if i < nums1.length
                nums<<nums1[i]
                i+=1
            else
                nums<<nums2[j]
                j+=1		
            end
        end
    end

    if (nums1.length + nums2.length)%2 == 1
        mid = nums.last.to_f
    else
        mid = (nums[nums.length-1]+nums[nums.length-2])/2.0
    end
    return mid
end
```
