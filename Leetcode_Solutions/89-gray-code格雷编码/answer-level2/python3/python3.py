    def grayCode(self, n: int) -> List[int]:
        gray = [0]
        for i in range(n):
            ans = []
            for g in gray[::-1]:
                ans.append(g + 2 ** i)
            gray.extend(ans)
        return gray