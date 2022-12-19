```
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        max_num = int((-1 + (1 + 8 * candies)**0.5) / 2)
        cyc = int(max_num / num_people)
        red = max_num % num_people
        ans = [0] * num_people
        if cyc > 0:
            more = (cyc - 1) * cyc / 2 * num_people
            for i in range(num_people):
                ans[i] = int(cyc * (i + 1) + more)

        now_div = int(cyc) * num_people
        last_can = int(candies - (1 + now_div) * now_div / 2)
        if last_can > 0:
            i = 0
            now = now_div
            while last_can > 0:
                now += 1
                if last_can <= now:
                    now = last_can
                ans[i] += now
                # print(i, ans[i])
                last_can -= now
                i += 1

        return ans
```
