define(["background/storage","models/nodeinfo"],function(i,e){var d={host:"ws://0.0.0.0:1743",nodeID:void 0,sessionID:void 0,serverKey:void 0};return{details:function(){return new Promise(function(e,n){var o=i.get("server"),s=i.get("nodeinfo"),r=i.get("sessionID");Promise.all([o,s,r]).then(function(e){var n;!e[0]||(n=e[0])&&n.server&&(d.host="ws://"+n.server.name+":"+n.server.port),e[1]&&e[1].nodeinfo&&(d.nodeID=e[1].nodeinfo.id.nodeid,d.serverKey=e[1].nodeinfo.id.serverkey),e[2]&&(d.sessionID=e[2].sessionID)}).then(function(){e(d)}).catch(n)})}}});