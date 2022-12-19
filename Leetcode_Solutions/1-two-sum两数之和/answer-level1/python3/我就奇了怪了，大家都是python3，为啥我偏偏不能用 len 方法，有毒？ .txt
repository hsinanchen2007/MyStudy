
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_list  = len(List)
        for i,data1 in enumerate(List):
            if data1 > target:
                continue
            for j,data2 in enumerate(List[i:]):
                sum_two = data1 + data2
                if sum_two == target:
                    return i, j







执行完成，耗时：N/A
TypeError: object of type '_GenericAlias' has no len()
    nums_list  = len(List)
Line 3 in twoSum (Solution.py)
    ret = Solution().twoSum(nums, target)
Line 44 in main (Solution.py)
    main()
Line 52 in <module> (Solution.py)