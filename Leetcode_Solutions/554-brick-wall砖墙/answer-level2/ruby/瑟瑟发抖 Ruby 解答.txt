```
# @param {Integer[][]} wall
# @return {Integer}
def least_bricks(wall)
  return 0 if wall.size == 1 && wall[0].size!=1
  res = {}
    wall.each_index do |i|
      @tmp=0
      wall[i].each_index do |j|
        @tmp=@tmp+wall[i][j]
        res.has_key?(@tmp) ? res.store(@tmp,res[@tmp]+1) : res.store(@tmp,1)
      end
    end
  res.size >1 ? res.values.sort[-1]-res.values.sort[-2] : wall.size
end
```
