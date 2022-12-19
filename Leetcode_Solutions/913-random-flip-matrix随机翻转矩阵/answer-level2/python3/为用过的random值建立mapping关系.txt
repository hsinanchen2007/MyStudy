
```
import random
class Solution:

    def __init__(self, n_rows: int, n_cols: int):
        self.flapped_mapping={}
        self.flapped_cnt=0
        self.total=n_rows*n_cols
        self.n_rows=n_rows
        self.n_cols=n_cols

                

    # While calc the random posi value, mapping the chosen posi value with max_posi. If the chosen posi value return again from random, then use the mapped max posi instead.
    def flip(self) -> List[int]:
        max_posi=self.total-1-self.flapped_cnt
        chosen=random.randint(0,max_posi)
        #print(f"Begin: chosen:{chosen} max_posi:{max_posi} flapped_cnt:{self.flapped_cnt} flapped_mapping:{self.flapped_mapping}")
        
        res=chosen
        # The chosen posi used before, so pick up the alternative posi value from mapping
        # keep loopping unitl found a un-used max posi value
        while self.flapped_mapping.get(res):
            res=self.flapped_mapping[res]
        
        self.flapped_mapping[chosen]=max_posi
        #print(f"End: chosen:{chosen} max_posi:{max_posi} flapped_cnt:{self.flapped_cnt} flapped_mapping:{self.flapped_mapping} res:{res} [{res//self.n_cols},{res%self.n_cols}] ")

        self.flapped_cnt+=1
        
        return [res//self.n_cols,res%self.n_cols]

    def reset(self) -> None:
        self.flapped_mapping.clear()
        self.flapped_cnt=0
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()
```