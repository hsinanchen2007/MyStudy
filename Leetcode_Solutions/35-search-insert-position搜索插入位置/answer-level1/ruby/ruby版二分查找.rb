def search_insert(nums, target)
  len = nums.length
  return 0 if len == 0 
  left = 0
  right = len 

  while(left < right)
    mid = (left + right) >> 1
    if nums[mid] < target
      left = mid + 1
    else
      right = mid 
    end
  end
  return left 
end