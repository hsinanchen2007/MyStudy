 SELECT ifnull(round(c/f,2),0) as accept_rate
 FROM( SELECT count(*) as c FROM(SELECT DISTINCT requester_id,accepter_id FROM request_accepted)a)b,
 (SELECT count(*) as f FROM(SELECT DISTINCT sender_id, send_to_id FROM friend_request)d)e;

第一步 分别对 好友申请和通过申请 两表去重
第二步 使用ifnull() 函数和round()函数 求通过率