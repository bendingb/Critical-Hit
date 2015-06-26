<h1>Muse</h1>

<h2>Input Data from Muse (via OSC)</h2>
<strong>/muse/acc - head tilts (x,y,z)</strong>
<ul>
<li>x: up/down</li>
<li>z: left/right</li>
</ul>

<strong>/muse/dsp/blink - blink (boolean value: 0, 1)</strong>
<ul>
<li>0 - no blink</li>
<li>1 - blink</li>
</ul>

<strong>/muse/elements/experimental/mellow - calm score (decimal value from 0 to 1)</strong>
<ul>
<li>0 - not calm/mellow</li>
<li>1 - very calm/mellow</li>
</ul>

<h4>Additional Resources</h4>
https://sites.google.com/a/interaxon.ca/muse-developer-site/museio/osc-paths/osc-paths---v3-6-0
<br/><br/>
<h2>Multiple Muses</h2>
To start getting data from multiple Muses, set up two different ports to listen to the devices (see below for example):
<ul>
<li>muse-io --device (Name of device#1) --osc osc.udp://localhost:5000</li>
<li>muse-io --device (Name of device#1) --osc osc.udp://localhost:5001</li>
</ul>
