define(["background/storageSync","models/useridentity"],function(o,n){var d=new e;function e(){return this.id={nodeid:void 0,altid:void 0,serverkey:void 0},this.info={computername:void 0,user:void 0,userdomain:"Chrome",domain:void 0,ipaddress:void 0,config:0,type:9},this}function i(i){return new Promise(function(e){e(JSON.stringify([{id:i.id},{info:i.info}]))})}function s(e){d.id.altid=e,d.info.computername=e,d.info.domain=e}return e.prototype.format=i,n.refresh.user(),n.refresh.device(),{node:function(){return new Promise(function(i,e){o.get("nodeinfo").then(function(e){e&&e.nodeinfo&&(d.id.nodeid=e.nodeinfo.id.nodeid,d.id.serverkey=e.nodeinfo.id.serverkey,d.id.altid=e.nodeinfo.id.altid)}),n.refresh.user().then(function(e){d.info.user=e,n.get().device?s(n.get().device):s(e),i(d)}).catch(e)})},webheader:function(e){return new Promise(function(i){var n={id:d.id};e?(n.id.sessionid=e,i(n)):o.get("sessionID").then(function(e){e&&e.sessionID&&(n.id.sessionid=e.sessionID),i(n)})})},setId:function(e,i,n){o.set({sessionID:i}),d.id.nodeid=e,d.id.serverkey=n,o.set({nodeinfo:d})},setInfo:function(){return new Promise(function(e,i){i("Not Implemented")})},format:i,clearSession:function(){delete d.id.sessionid,o.remove("sessionID")}}});