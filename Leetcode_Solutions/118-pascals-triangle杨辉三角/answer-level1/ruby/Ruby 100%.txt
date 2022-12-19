```
# @param {Integer} num_rows
# @return {Integer[][]}
def generate(num_rows)
    dp = []

    (num_rows).times do |num_row|
      row = []
      (num_row+1).times do |step|
        row[step] = nil
      end
 
      row[0], row[-1] = 1, 1

      for i in (1..num_row - 1)
        row[i] = dp[num_row - 1][i - 1] + dp[num_row - 1][i]
      end

      dp.push(row)
    end
    
    dp
      

end
```
