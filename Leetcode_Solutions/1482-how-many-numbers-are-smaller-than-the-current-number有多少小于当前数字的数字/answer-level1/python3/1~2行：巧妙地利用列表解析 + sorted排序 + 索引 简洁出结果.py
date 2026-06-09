
        nums_sort = sorted(nums)
        return [nums_sort.index(n) for n in nums]

(其实写成一行也行, 但是慢很多, 因为每次 for 循环都要 sorted 一次)