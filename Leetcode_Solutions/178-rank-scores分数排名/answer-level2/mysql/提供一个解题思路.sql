select Score, CONVERT(Rank, signed) Rank
from (select Score, 
(case 
when @Prev = Score then @scoreRank
when @Prev := Score then @scoreRank := @scoreRank + 1
else  @scoreRank := @scoreRank + 1
end
)Rank
from Scores a,(select @scoreRank := 0, @Prev := null) b
order by Score desc) z