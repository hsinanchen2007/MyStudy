select d.Score,Rank from Scores d left join (select convert(@rowNum:=@rowNum+1,signed) Rank,Score from (select distinct Score from Scores order by Score desc) a,(select @rowNum:=0) b) c on d.Score=c.Score order by d.Score desc;

第一步：查询出不同分数对应的等级
 1.1 select distinct Score from Scores order by Score desc 降序查询出不重复的分数
 1.2 给不同的分数添加上等级
select convert(@rowNum:=@rowNum+1,signed) Rank,Score from (select distinct Score from Scores order by Score desc) a,(select @rowNum:=0) b

第二部： 用分数关联，则每个分数可获得上它对应的等级，再根据分数降序排列
select d.Score,Rank from Scores d left join (select convert(@rowNum:=@rowNum+1,signed) Rank,Score from (select distinct Score from Scores order by Score desc) a,(select @rowNum:=0) b) c on d.Score=c.Score order by d.Score desc;

