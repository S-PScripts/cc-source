!function(e){"function"==typeof define&&define.amd?define(["settings","student","disconnect","modules/window","modules/extension","comms.websocket","background/subscription"],e):"object"==typeof exports&&(module.exports=e(require("settings"),require("student"),require("disconnect"),require("modules/window"),require("modules/extension"),require("comms.websocket"),require("background/subscription"),require("on/lifecycle")))}(function(r,e,s,t,o,a,c,n){var i={heartBeat:void 0,rapidResponder:void 0};class d{constructor(e){n||require(["on/lifecycle"],e=>n=e),this.handlers=e,this._expired=[],this.Create()}Create(){var e=this.socket;return new Promise((t,n)=>{r.setSelectedGatewayAddressPort().then(e=>{if(""!==e.address&&null!=e.address&&"undefined"!==e.address.toLowerCase())try{localStorage.connectionState="connecting",chrome.runtime.sendMessage({storeLocal:!0,data:{connectionState:"connecting"}}),this.socket=new WebSocket("wss://"+e.address+":"+e.port),o.setGWFlag(e.flag),new a.Commands(this,this.socket),d.bind(this.handlers,this.socket),t(this.socket)}catch(e){"0"===o.getGWFlag()||"null"==o.getGWFlag()?o.setGWFlag("1"):o.setGWFlag("0"),n(e)}else n("No Socket Address")}),e&&(1==e.readyState&&e.close(1e3,"SOCKET_EXPIRED"),2==e.readyState&&(e.onclose=void 0)),this._expired.push(e)})}isStale(){var e=n.check();return!(this.socket&&!(this.socket&&1<this.socket.readyState)&&e)&&(o.setGWFlag(null),!0)}recycle(){this.Create()}HeartBeat(){i.heartBeat&&t.clearInterval(i.heartBeat),i.heartBeat=t.setInterval(()=>c.on.heartbeat.call(),6e4)}static bind(e,t){return t.onerror=e.error,t.onopen=e.open,t.onclose=e.close,t.onmessage=e.message,t.binaryType="arraybuffer",t}static accelerateReconnect(){debug("...Accelerate Reconnect"),c.on.heartbeat.call();var t=setTimeout(function(){s.reset(),c.on.interval.call()},7e3),n=setInterval(function(){var e=(new Date).toISOString();a.instance.websocket&&1===a.instance.websocket.readyState&&a.instance.POLL(e)},750);debug("Emitting..."),addEventListener(i.rapidResponder,function e(){localStorage.connectionState="connected_NCS",chrome.runtime.sendMessage({storeLocal:!0,data:{connectionState:"connected_NCS"}}),debug("...Echo Received"),debug("Remove Emitter"),clearInterval(n),removeEventListener(i.rapidResponder,e),clearTimeout(t),o.handshake()}),setTimeout(function(){clearInterval(n)},1e4)}}return d});