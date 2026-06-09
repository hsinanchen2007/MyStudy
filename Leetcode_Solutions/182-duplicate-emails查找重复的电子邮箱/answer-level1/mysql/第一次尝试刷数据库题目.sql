数据库知识还未完全掌握，来尝试一个简单题目。
利用双表联合的方式进行查询，效率较低。
`select distinct p1.Email from person p1, person p2
where p1.id<>p2.id and p1.Email=p2.Email;`