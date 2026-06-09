# 自己根据官方解法写了一个Ruby版，😂不得不说困难的题还是的确有些难度的
# ```ruby
# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}                
def find_median_sorted_arrays(nums1, nums2)
    m = nums1.length
    n = nums2.length 
    # ensure m<=n 
    if m > n 
        temp = nums1
        nums1 = nums2
        nums2 = temp 
        tmp = n 
        n = m 
        m = tmp
    end
    i_min = 0 
    i_max = m 
    half_len = (m + n + 1) / 2
    while(i_min <= i_max) do 
        i = (i_min + i_max) / 2
        j = half_len - i 
        if (i < i_max) && (nums2[j-1] > nums1[i])
            # i is too small 
            # actually it would only need i + 1 but 有奇数和偶数的可能
            i_min = i + 1
        elsif (i > i_min) && (nums1[i-1] > nums2[j])
            # i is too big
            i_max = i - 1 
        else 
            # i is perfect
            # note that i + j 永远是总长度的一半，可以直接返回
            max_left = 0;
            if i == 0 
                max_left = nums2[j-1]
            elsif j == 0 
                max_left = nums1[i-1]
            else 
                max_left = [nums1[i-1], nums2[j-1]].max
            end
            if (m + n) % 2 == 1
                return max_left
            end
            min_right = 0 
            if i == m 
                min_right = nums2[j]
            elsif j == n 
                min_right = nums1[i]
            else 
                min_right = [nums1[i], nums2[j]].min
            end 
            return (max_left + min_right) / 2.0
        end 
    end
    return 0.0   
end
# ```
