```
    def constructRectangle(self, area: int) -> List[int]:
        left = 0
        right = area

        while left < right:
            mid = (left + right + 1) >> 1
            cur_val = mid * mid
            if cur_val > area:
                right = mid - 1
            else:
                left = mid

        for index in range(left, 0, -1):
            if area % index == 0:
                break
        return [area//index, index]
```
