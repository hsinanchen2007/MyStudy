    def rotatedDigits(self, N: int) -> int:
        nums = {'0': '0', '1': '1', '2': '5', '5': '2', '6': '9', '8': '8', '9': '6'}
        count = 0
        for i in range(1, N + 1):
            str_num = str(i)
            temp_num = ''
            for s in str_num:
                if s not in nums:
                    break
                temp_num += nums[s]
            if len(temp_num) == len(str_num) and temp_num != str_num:
                count += 1
        return count