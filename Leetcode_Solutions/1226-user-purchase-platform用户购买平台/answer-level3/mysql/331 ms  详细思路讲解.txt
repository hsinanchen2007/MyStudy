**第一步** 观察样例
先观察样例，结果是按照时间和平台分组的，每个日期都对应了三个完整的平台，这种结构，是不是很像笛卡尔积呢（cross join）？
*忘记的同学复习一下，假设集合A={a, b}，集合B={0, 1, 2}，则两个集合的笛卡尔积为{(a, 0), (a, 1), (a, 2), (b, 0), (b, 1), (b, 2)}。*
因此，我们要是在时间和平台笛卡尔积基础上有了对应的实际数据，就可以进行统计了。
**第二步** 问题拆解
那么，我们的问题就可以拆解并分成以下几个步骤：
    ①原始表没有both的分类，我们加工下把他加上；
    ②最好有个完整的时间和分类表（笛卡尔积）
    ③我们把①表和②表left join一下，得到null值以方便进行0值的统计
    ④得到上述结果后，输出结论就是简单的group by操作了
**第三步** 分步操作得出结果
①:原始表加工，即创建新列platform和amount。（记录数6条——>5条）
```
select 
    a.user_id,a.spend_date,
    if(count(*)=1,a.platform,'both') as platform,   -- 根据同一天同用户的记录数，确定是否为'both'
    if(count(*)=1,a.amount,sum(a.amount)) as amount -- 同理，按条件分别输出amount与sum(amount)
from Spending a        -- 加a以作区分
group by user_id,spend_date
```

②：获取完整的时间和分类表。即时间和数组（'desktop'，'mobile'，'both'）的笛卡尔积。
    1）这里由于不知道如何自定义一组数据作为一列，因此采用了2次union的方法，即以select 'desktop'作为单列单行数据，进行2次拼接，最终得到一个三行一列包含'desktop'，'mobile'，'both'的临时表a；
    2）获取源数据中的完整日期信息，作临时表b
    3）a，b取笛卡尔积。
```
select spend_date,platform from 
(select * from (select 'desktop' as platform) a union (select 'mobile') union (select 'both')) a,(select distinct spend_date from Spending) b
```

③+④：结果为按时间和平台分组，为了应对有些时间某平台记录为0，应以完整记录表left join出空值
```
select c.spend_date,c.platform,ifnull(sum(d.amount),0) as total_amount,count(d.user_id) as total_users
from 
    (select spend_date,platform from                    -- -------------------------
        (select * from (select 'desktop' as platform) b   -- 表②
        union (select 'mobile') union (select 'both')) e, -- |||||||||||||
        (select distinct spend_date from Spending) f) c  -- ------------------------
    left join                                            -- 左连接
    (select a.user_id,a.spend_date,                      -- ------------------------- 
        if(count(*)=1,a.platform,'both') as platform,    -- |||||||||||||
        if(count(*)=1,a.amount,sum(a.amount)) as amount  -- 表①
    from Spending a                                      -- |||||||||||||
    group by user_id,spend_date) d                       -- -------------------------
    on c.spend_date=d.spend_date and c.platform=d.platform -- 连接条件
group by c.spend_date,c.platform
order by field(c.platform,'desktop','mobile','both'),c.spend_date
```
补充一点，为了自定义平台的排列顺序，可以用field函数。语法如下：field(数据来源列,自己写的顺序逗号分割)