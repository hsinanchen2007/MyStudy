
SELECT requester_id id,SUM(a_cnt) num FROM
(
    SELECT requester_id,COUNT(1) a_cnt FROM request_accepted GROUP BY requester_id 

    UNION ALL

    SELECT accepter_id,COUNT(1) b_cnt FROM request_accepted GROUP BY accepter_id

    ORDER BY requester_id   
) temp
    GROUP BY requester_id
    ORDER BY num DESC limit 1